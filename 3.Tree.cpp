#include <iostream>
#include <string>
using namespace std;

struct node // Node Declaration
{
    string label;         // Name of the current node (Book, Chapter, Section, or Subsection)
    int ch_count;         // Number of children (Chapters, Sections, or Subsections)
    struct node *child[10]; // Array of child nodes
} * root;

class GT // Class Declaration
{
public:
    void create_tree(); //Here we are creating tree
    void display(node *r1); //displaying method

    GT()
    {
        root = NULL; //After creating root node here we are assigning it null
    }
};

void GT::create_tree()
{
    int tchapters, tsections, tsubsections, i, j, k;
    root = new node;

    cout << "Enter name of book: ";
    cin.ignore();                       // Clear input buffer
    getline(cin, root->label);

    cout << "Enter number of chapters in the book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter the name of Chapter " << i + 1 << ": ";
        cin.ignore();
        getline(cin, root->child[i]->label);

        cout << "Enter number of sections in Chapter " << root->child[i]->label << ": ";
        cin >> tsections;
        root->child[i]->ch_count = tsections;

        for (j = 0; j < tsections; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter name of Section " << j + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->child[j]->label);

            cout << "Enter number of subsections in Section " << root->child[i]->child[j]->label << ": ";
            cin >> tsubsections;
            root->child[i]->child[j]->ch_count = tsubsections;

            for (k = 0; k < tsubsections; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter name of Subsection " << k + 1 << ": ";
                cin.ignore();
                getline(cin, root->child[i]->child[j]->child[k]->label);
            }
        }
    }
}

void GT::display(node *r1)
{
    int i, j, k;

    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";
        cout << "\nBook title: " << r1->label;

        for (i = 0; i < r1->ch_count; i++)
        {
            cout << "\nChapter " << i + 1 << ": " << r1->child[i]->label;

            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  Section " << j + 1 << ": " << r1->child[i]->child[j]->label;

                for (k = 0; k < r1->child[i]->child[j]->ch_count; k++)
                {
                    cout << "\n    Subsection " << k + 1 << ": " << r1->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int choice;
    GT gt;

    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Menu" << endl;
        cout << "-----------------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice Here->: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;

        case 2:
            gt.display(root);
            break;

        case 3:
            cout << "Exiting...."<< endl;
            exit(1);

        default:
            cout << "Wrong choice!!!" << endl;
        }
    }

    return 0;
}