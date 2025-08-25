#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class HRMLTree
{
private:
    string m_tag;
    map<string, string> m_attributes;
    HRMLTree *nested_tag;

public:
    void parse_HRML_line(const string &tag_line)
    {
        int tag_end = tag_line.find(" ");
        string tag = tag_line.substr(1, tag_end - 1);
        m_tag = tag;
    }
};

int main()
{
    int tag_lines, queries;
    cin >> tag_lines >> queries;

    // cin >> leaves an endl tag so next getline() reads empty line. this is used to prevent it
    cin.get();

    vector<HRMLTree> trees;

    char temp_tag_line[200];
    cin >> temp_tag_line;
    string tag_line(temp_tag_line);

    HRMLTree tree;

    tree.parse_HRML_line(tag_line);
}
