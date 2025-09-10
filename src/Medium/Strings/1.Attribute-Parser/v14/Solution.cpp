#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

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
    string findAttribute(const string &attribute_name)
    {
        map<string, string>::iterator it;
        if ((it = m_attributes.find(attribute_name)) == m_attributes.end())
            return "Not Found!";

        return it->second;
    }
    void parseHRMLTagLine(string tag_line)
    {
        tag_line = tag_line.substr(1, tag_line.size() - 2);
        string attributes = parseTag(tag_line);
        parseAttributes2(attributes);
    }
    string parseTag(const string &tag_line)
    {
        int end = tag_line.find(' ');
        if (end == string::npos)
            end = tag_line.size();

        string tag = tag_line.substr(0, end);
        setTag(tag);

        return tag_line.substr(end);
    }
    void parseAttributes2(const string &attributes)
    {
        istringstream iss(attributes);
        string attribute_name, delimiter, attribute_value;

        while (iss >> attribute_name >> delimiter >> quoted(attribute_value))
        {
            m_attributes[attribute_name] = attribute_value;
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
    string line;
    line.reserve(200);
    getline(cin, line);
    return line;
}

void readHRMLTree(HRMLTree *parent, uint16_t tag_lines_count)
{
    while (tag_lines_count > 0)
    {
        string tag_line = readLine();

        if (tag_line[1] == '/') // is ending tag?
        {
            parent = parent->getParent();
        }
        else
        {
            HRMLTree *child = new HRMLTree;
            child->parseHRMLTagLine(tag_line);
            child->setParent(parent);
            parent->addChild(child);
            parent = child;
        }
        tag_lines_count--;
    }
}

HRMLTree *findChild(HRMLTree *parent, const string &tag)
{
    for (HRMLTree *child : parent->getChilds())
    {
        if (child->getTag() == tag)
            return child;
    }

    return nullptr;
}

void printQueries(HRMLTree *parent, uint16_t query_count)
{
    while (query_count > 0)
    {
        string query = readLine();

        // split attribute name and tags
        int tilde_index = query.find('~');
        string attribute_name = query.substr(tilde_index + 1);
        string tags = query.substr(0, tilde_index);

        // loop over tags
        HRMLTree *parent_ref = parent;
        istringstream iss(tags);
        string tag;

        while (getline(iss, tag, '.'))
        {
            parent_ref = findChild(parent_ref, tag);
            if (!parent_ref)
                break;
        }

        // print values
        if (!parent_ref)
            cout << "Not Found!" << endl;
        else
            cout << parent_ref->findAttribute(attribute_name) << endl;

        query_count--;
    }
}

int main()
{
    uint16_t tag_lines_count, query_count;
    cin >> tag_lines_count >> query_count;
    cin.ignore();

    HRMLTree *tree = new HRMLTree;
    readHRMLTree(tree, tag_lines_count);
    printQueries(tree, query_count);

    delete tree;
}