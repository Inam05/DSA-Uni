#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class WebPage
{
public:
    string url;
    string title;
    string timestamp;
    WebPage *prev;
    WebPage *next;

    WebPage(const string &url, const string &title)
        : url(url), title(title), prev(nullptr), next(nullptr)
    {
        // Capture current time as the timestamp
        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back(); // Remove newline character from timestamp
    }
};

class BrowserNavigationSystem
{
private:
    WebPage *current;      // Current page in the browser
    WebPage *historyStart; // Start of the browsing history

    void deleteWebPage(WebPage *page)
    {
        if (!page)
            return;

        if (page->prev)
            page->prev->next = page->next;
        if (page->next)
            page->next->prev = page->prev;

        if (page == current)
            current = page->next ? page->next : page->prev;

        if (page == historyStart)
            historyStart = page->next;

        delete page;
    }

public:
    BrowserNavigationSystem() : current(nullptr), historyStart(nullptr) {}

    // 1. Visit a new page
    void visitPage(const string &url, const string &title)
    {
        WebPage *newPage = new WebPage(url, title);
        if (current != nullptr)
        {
            // Discard forward history
            WebPage *temp = current->next;
            while (temp != nullptr)
            {
                WebPage *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }

            current->next = newPage;
            newPage->prev = current;
        }
        else
        {
            historyStart = newPage; // First page visited
        }

        current = newPage;
        cout << "Visited: " << title << " (" << url << ") at " << current->timestamp << endl;
    }

    // 2. Back
    void goBack()
    {
        if (current == nullptr || current->prev == nullptr)
        {
            cout << "No previous pages to go back to." << endl;
            return;
        }

        current = current->prev;
        cout << "Moved back to: " << current->title << " (" << current->url << ") at " << current->timestamp << endl;
    }

    // 3. Forward
    void goForward()
    {
        if (current == nullptr || current->next == nullptr)
        {
            cout << "No forward pages to go to." << endl;
            return;
        }

        current = current->next;
        cout << "Moved forward to: " << current->title << " (" << current->url << ") at " << current->timestamp << endl;
    }

    // 4. View full history
    void viewHistory()
    {
        if (historyStart == nullptr)
        {
            cout << "No browsing history." << endl;
            return;
        }

        WebPage *temp = historyStart;
        cout << "Browsing History:" << endl;
        while (temp != nullptr)
        {
            cout << "Page Title: " << temp->title << ", URL: " << temp->url << ", Visited At: " << temp->timestamp << endl;
            temp = temp->next;
        }
    }

    // 5. Delete a specific page from history
    void deletePageFromHistory(const string &url)
    {
        WebPage *temp = historyStart;
        while (temp != nullptr)
        {
            if (temp->url == url)
            {
                deleteWebPage(temp);
                cout << "Deleted page with URL: " << url << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Page with URL " << url << " not found in history." << endl;
    }

    // 6. Clear history
    void clearHistory()
    {
        while (historyStart != nullptr)
        {
            WebPage *temp = historyStart;
            historyStart = historyStart->next;
            delet============

    // 7. History Search by URL or Title
    void searchHistory(const string &query)
    {
        WebPage *temp = historyStart;
        cout << "Search results for '" << query << "':" << endl;
        while (temp != nullptr)
        {
            if (temp->url.find(query) != string::npos || temp->title.find(query) != string::npos)
            {
                cout << "Found: " << temp->title << " (" << temp->url << ") at " << temp->timestamp << endl;
            }
            temp = temp->next;
        }
    }

    // 8. Revisit Strategy (LRU Cache Behavior)
    void revisitPage(const string &url, const string &title)
    {
        WebPage *temp = historyStart;
        while (temp != nullptr)
        {
            if (temp->url == url)
            {
                deleteWebPage(temp);
                visitPage(url, title);
                cout << "Revisited: " << title << " (" << url << ")" << endl;
                return;
            }
            temp = temp->next;
        }

        // If not found, visit as a new page
        visitPage(url, title);
    }
};

// Main function with a menu for testing the browser system
int main()
{
    BrowserNavigationSystem browser;
    int choice;
    string url, title;

    while (true)
    {
        cout << "\n--- Browser Navigation System Menu ---" << endl;
        cout << "1. Visit a new page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Forward" << endl;
        cout << "4. View full history" << endl;
        cout << "5. Delete a page from history" << endl;
        cout << "6. Clear history" << endl;
        cout << "7. Search history" << endl;
        cout << "8. Revisit a page" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore(); // Ignore newline from previous input
            cout << "Enter page URL: ";
            getline(cin, url);
            cout << "Enter page title: ";
            getline(cin, title);
            browser.visitPage(url, title);
            break;

        case 2:
            browser.goBack();
            break;

        case 3:
            browser.goForward();
            break;

        case 4:
            browser.viewHistory();
            break;

        case 5:
            cin.ignore(); // Ignore newline from previous input
            cout << "Enter page URL to delete: ";
            getline(cin, url);
            browser.deletePageFromHistory(url);
            break;

        case 6:
            browser.clearHistory();
            break;

        case 7:
            cin.ignore(); // Ignore newline from previous input
            cout << "Enter search query (URL or Title): ";
            getline(cin, url);
            browser.searchHistory(url);
            break;

        case 8:
            cin.ignore(); // Ignore newline from previous input
            cout << "Enter page URL to revisit: ";
            getline(cin, url);
            cout << "Enter page title: ";
            getline(cin, title);
            browser.revisitPage(url, title);
            break;

        case 9:
            cout << "Exiting the system." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
