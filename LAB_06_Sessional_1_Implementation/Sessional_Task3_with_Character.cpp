#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor
{
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    TextEditor()
    {
        text = "";
    }

    void insertCharacter(char character)
    {
        undoStack.push(text);

        text += character;

        while (!redoStack.empty())
        {
            redoStack.pop();
        }
    }

    void undo()
    {
        if (!undoStack.empty())
        {
            redoStack.push(text);

            text = undoStack.top();
            undoStack.pop();
        }
        else
        {
            cout << "Nothing to undo." << endl;
        }
    }

    void redo()
    {
        if (!redoStack.empty())
        {
            undoStack.push(text);

            text = redoStack.top();
            redoStack.pop();
        }
        else
        {
            cout << "Nothing to redo." << endl;
        }
    }

    void printCurrentText()
    {
        cout << "Current Text: " << text << endl;
    }
};

int main()
{
    TextEditor editor;
    char choice;

    cout << "Simple Text Editor" << endl;

    do
    {
        editor.printCurrentText();
        cout << "Options:" << endl;
        cout << "1. Insert Character" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            char character;
            cout << "Enter a character to insert: ";
            cin >> character;
            editor.insertCharacter(character);
            break;

        case '2':
            editor.undo();
            break;

        case '3':
            editor.redo();
            break;

        case '4':
            cout << "Exiting Text Editor." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
