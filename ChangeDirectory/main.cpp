#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * Write a function that provides change directory (cd) function for an abstract file system.
 * Notes:
 * Root path is '/'.
 * Path separator is '/'.
 * Parent directory is addressable as "..".
 * Directory names consist only of English alphabet letters (A-Z and a-z).
 * For example, Path("/a/b/c/d").cd("../x").getPath() should return "/a/b/c/x".
 * Note: The evaluation environment uses '\' as the path separator.
 */

class Path {
public:
	Path(std::string path) {
		currentPath = path;
	}

	std::string getPath() const {
		return currentPath;
	}

	Path cd(std::string newPath) const {
		int len = 0;
		const vector<string> paths = split(currentPath, "/");
		for (std::vector<string>::const_iterator it = paths.begin();
				it != paths.end(); ++it) {
			len++;
		}

		const vector<string> newPaths = split(newPath, "/");
		int count = 0;
		string lastPath = "";
		for (std::vector<string>::const_iterator it = newPaths.begin();
				it != newPaths.end(); ++it) {
			if (*it == "..") {
				count++;
			}
			lastPath = *it;
		}

		std::string str;
		std::vector<string>::const_iterator it = paths.begin();
		++it;
		for (int i = 1; i < len - count; i++) {
			str.append("/");
			str.append(*it);
			++it;
		}

		for (std::vector<string>::const_iterator it = newPaths.begin();
				it != newPaths.end(); ++it) {
			if (*it == "..") {
				continue;
			}
			str.append("/");
			str.append(*it);
		}

		return Path(str);
	}

	vector<string> split(const string& s, const string& delim,
			const bool keep_empty = true) const {
		vector < string > result;
		if (delim.empty()) {
			result.push_back(s);
			return result;
		}
		string::const_iterator substart = s.begin(), subend;
		while (true) {
			subend = search(substart, s.end(), delim.begin(), delim.end());
			string temp(substart, subend);
			if (keep_empty || !temp.empty()) {
				result.push_back(temp);
			}
			if (subend == s.end()) {
				break;
			}
			substart = subend + delim.size();
		}
		return result;
	}

private:
	std::string currentPath;
};

int main() {
	Path path("/a/b/c/d");
	cout << path.cd("../x").getPath() << endl;
	cout << path.cd("../../x").getPath() << endl;
	cout << path.cd("../../x/x").getPath() << endl;
	cout << path.cd("../../../../x/x").getPath() << endl;
}
