#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Command {
    string task;
    int user;
    int page;
};

Command ParseCommand(string& line) {
    int user;
    int page;
    if (line == "READ") {
        cin >> user;
        cin >> page;
        return {line, user, page};
    }
    if (line == "CHEER") {
        cin >> user;
        return {line, user, 0};
    }
    return {"WRONG", 0, 0};
}

class Books {
public:
    void ReadPages(int user, int pages) {
        if (user + 1 > read_pages.size()) {
            read_pages.resize(user + 1, 0);
        }
        int from = read_pages[user] > 0 ? read_pages[user] + 1 : 1;
        read_pages[user] = pages;

        if (pages + 1 > users_pages.size()) {
            users_pages.resize(pages + 1, 0);
        }
        for (int i = from; i <= pages; ++i) {
            ++users_pages[i];
        }
    };

    void CheerUser(int user) {
        if (user >= read_pages.size() || users_pages[read_pages[user]] == 0) {
            cout << 0 << endl;
            return;
        }
        if (users_pages[1] == 1) {
            cout << 1 << endl;
            return;
        }
        double users = users_pages[1];
        cout << setprecision(6) << (users - users_pages[read_pages[user]]) / (users - 1) << endl;
    }

private:
    vector<int> read_pages;
    vector<int> users_pages;
};

int main() {
    int num;
    cin >> num;
    Books books;

    for (int i = 0; i < num; ++i) {
        string line;
        cin >> line;
        auto command = ParseCommand(line);
        if (command.task == "READ") {
            books.ReadPages(command.user, command.page);
        }
        if (command.task == "CHEER") {
            books.CheerUser(command.user);
        }
    }
}
