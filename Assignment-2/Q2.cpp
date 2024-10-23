#include <iostream>
#include <string>
using namespace std;

class UserProfile
{
public:
    int userID;
    string name;
    int mutualFriendsCount;
    string status; // "Suggested" or "Not Suggested"
    UserProfile *next;

    UserProfile(int id, const string &name, int mutualFriends)
        : userID(id), name(name), mutualFriendsCount(mutualFriends), status("Suggested"), next(nullptr) {}
};

class FriendSuggestionSystem
{
private:
    UserProfile *suggestionList;

public:
    FriendSuggestionSystem() : suggestionList(nullptr) {}

    // 1. Add a new profile
    void addProfile(int userID, const string &name, int mutualFriends)
    {
        UserProfile *newUser = new UserProfile(userID, name, mutualFriends);
        newUser->next = suggestionList;
        suggestionList = newUser;
        cout << "Profile added for user: " << name << " with " << mutualFriends << " mutual friends." << endl;
    }

    // 2. Display friend suggestions
    void displaySuggestions()
    {
        if (suggestionList == nullptr)
        {
            cout << "No suggestions available." << endl;
            return;
        }

        UserProfile *current = suggestionList;
        cout << "Friend Suggestions: " << endl;
        while (current != nullptr)
        {
            if (current->status == "Suggested")
            {
                cout << "User ID: " << current->userID << ", Name: " << current->name << ", Mutual Friends: " << current->mutualFriendsCount << endl;
            }
            current = current->next;
        }
    }

    // 3. Add as friend
    void addAsFriend(int userID)
    {
        UserProfile *current = suggestionList;
        while (current != nullptr)
        {
            if (current->userID == userID && current->status == "Suggested")
            {
                current->status = "Not Suggested";
                cout << current->name << " has been added as a friend." << endl;
                return;
            }
            current = current->next;
        }
        cout << "User ID not found or already added as friend." << endl;
    }

    // 4. Top N suggestions based on mutual friends
    void displayTopNSuggestions(int N)
    {
        if (suggestionList == nullptr)
        {
            cout << "No suggestions available." << endl;
            return;
        }

        UserProfile *current = suggestionList;
        int count = 0;
        cout << "Top " << N << " Friend Suggestions: " << endl;
        while (current != nullptr && count < N)
        {
            if (current->status == "Suggested")
            {
                cout << "User ID: " << current->userID << ", Name: " << current->name << ", Mutual Friends: " << current->mutualFriendsCount << endl;
                count++;
            }
            current = current->next;
        }
    }

    // 5. Remove friend suggestion by User ID
    void removeSuggestion(int userID)
    {
        if (suggestionList == nullptr)
        {
            cout << "No suggestions to remove." << endl;
            return;
        }

        UserProfile *current = suggestionList;
        UserProfile *previous = nullptr;

        while (current != nullptr && current->userID != userID)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "User ID not found." << endl;
            return;
        }

        if (previous == nullptr) // Removing the head node
        {
            suggestionList = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        cout << "Friend suggestion removed." << endl;
    }

    // 6. Update mutual friends count
    void updateMutualFriends(int userID, int newCount)
    {
        UserProfile *current = suggestionList;
        while (current != nullptr)
        {
            if (current->userID == userID)
            {
                current->mutualFriendsCount = newCount;
                cout << "Mutual friends count updated for " << current->name << "." << endl;
                return;
            }
            current = current->next;
        }
        cout << "User ID not found." << endl;
    }

    // 7. Exit (No actual function required in this case, just placeholder)
    void exitSystem()
    {
        cout << "Exiting the system." << endl;
    }
};

// Main function with menu-driven system
int main()
{
    FriendSuggestionSystem system;
    int choice, userID, mutualFriends, N;
    string name;

    while (true)
    {
        cout << "\n--- Friend Suggestion System Menu ---" << endl;
        cout << "1. Add a new profile" << endl;
        cout << "2. Display friend suggestions" << endl;
        cout << "3. Add as friend" << endl;
        cout << "4. Display top N friend suggestions" << endl;
        cout << "5. Remove friend suggestion by User ID" << endl;
        cout << "6. Update mutual friends count" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore(); // Ignore newline from the previous input
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter number of mutual friends: ";
            cin >> mutualFriends;
            system.addProfile(userID, name, mutualFriends);
            break;

        case 2:
            system.displaySuggestions();
            break;

        case 3:
            cout << "Enter User ID to add as friend: ";
            cin >> userID;
            system.addAsFriend(userID);
            break;

        case 4:
            cout << "Enter the number of top suggestions to display: ";
            cin >> N;
            system.displayTopNSuggestions(N);
            break;

        case 5:
            cout << "Enter User ID to remove suggestion: ";
            cin >> userID;
            system.removeSuggestion(userID);
            break;

        case 6:
            cout << "Enter User ID to update mutual friends count: ";
            cin >> userID;
            cout << "Enter new mutual friends count: ";
            cin >> mutualFriends;
            system.updateMutualFriends(userID, mutualFriends);
            break;

        case 7:
            system.exitSystem();
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
