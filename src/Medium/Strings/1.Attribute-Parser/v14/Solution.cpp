#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class HRMLTree
{
private:
    HRMLTree *m_parent = nullptr;
    string m_tag;
    map<string, string> m_attributes;
    vector<HRMLTree *> m_childs;

public:
    void setTag(string tag)
    {
        m_tag = tag;
    }
    void setParent(HRMLTree *parent)
    {
        m_parent = parent;
    }
    string getTag()
    {
        return m_tag;
    }
    const vector<HRMLTree *> &getChilds()
    {
        return m_childs;
    }
    HRMLTree *getParent()
    {
        return m_parent;
    }
    void addChild(HRMLTree *tree)
    {
        m_childs.push_back(tree);
    }
    string findAttribute(string attribute_name)
    {
        map<string, string>::iterator it;
        if ((it = m_attributes.find(attribute_name)) == m_attributes.end())
            return "Not Found!";

        return it->second;
    }
    void parseHRMLTagLine(string tag_line)
    {
        parseTag(tag_line);
        parseAttributes(tag_line);
    }
    void parseTag(string tag_line)
    {
        tag_line = tag_line.substr(0, tag_line.size() - 1);
        int tag_end = tag_line.find(" ");
        string tag = tag_line.substr(1, tag_end - 1);
        setTag(tag);
    }
    void parseAttributes(string tag_line)
    {
        // logic:
        // find = sign then find attribute to the left of = sign then find value to the right of = sign
        // sample input: <tag8 intval = "34" floatval = "9.845">
        string attribute, value;
        int equal_pos = 0;
        // equal_offset is there to ignore first space before or after equal sign
        int equal_offset = 2;
        while ((equal_pos = tag_line.find("=", equal_pos)) != string::npos)
        {
            // find attribute
            int left_end = equal_pos - equal_offset;
            int left_start = tag_line.find_last_of(" ", left_end) + 1;
            attribute = tag_line.substr(left_start, left_end - left_start + 1);

            // find value
            int right_start = tag_line.find("\"", equal_pos) + 1;
            int right_end = tag_line.find("\"", right_start);
            value = tag_line.substr(right_start, right_end - right_start);

            m_attributes[attribute] = value;

            equal_pos++;
        }
    }
    ~HRMLTree()
    {
        for (HRMLTree *child : m_childs)
            delete child;

        m_childs.clear();
    }
};

string readLine()
{
    char temp_tag_line[200];
    cin.getline(temp_tag_line, 200);
    return string(temp_tag_line);
}

void readHRMLTree(HRMLTree *root, uint16_t tag_lines_count)
{
    while (tag_lines_count > 0)
    {
        string tag_line = readLine();

        if (tag_line[1] == '/') // is ending tag?
        {
            root = root->getParent();
        }
        else
        {
            HRMLTree *child = new HRMLTree;
            child->parseHRMLTagLine(tag_line);
            child->setParent(root);
            root->addChild(child);
            root = child;
        }
        tag_lines_count--;
    }
}

void printQueries(HRMLTree *root, uint16_t query_count)
{
    HRMLTree *root_ref;
    while (query_count > 0)
    {
        root_ref = root;
        bool found = true;

        string query = readLine();
        int tilde_index = query.find('~');
        string attribute_name = query.substr(tilde_index + 1, query.size() - tilde_index);
        query = query.substr(0, tilde_index);

        int pos = 0;
        int from = 0;
        while ((pos = query.find('.')) != string::npos && found)
        {
            string tag = query.substr(from, pos);
            for (HRMLTree *child : root_ref->getChilds())
            {
                if (tag == child->getTag())
                {
                    found = true;
                    query = query.substr(pos + 1, query.size() - pos);
                    root_ref = child;
                    break;
                }
                found = false;
            }
        }

        string tag = query;
        if (root_ref->getChilds().size() == 0)
            found = false;
        else
            for (HRMLTree *child : root_ref->getChilds())
            {
                if (tag == child->getTag())
                {
                    root_ref = child;
                    found = true;
                    break;
                }
                found = false;
            }

        if (!found)
            cout << "Not Found!" << endl;
        else
            cout << root_ref->findAttribute(attribute_name) << endl;

        query_count--;
    }
}

int main()
{
    uint16_t tag_lines_count, query_count;
    cin >> tag_lines_count >> query_count;
    cin.ignore();

    HRMLTree *tree = new HRMLTree;
    tree->setTag("root");
    readHRMLTree(tree, tag_lines_count);
    printQueries(tree, query_count);

    delete tree;
}