class Solution {
public:
    string convertToString(deque<string>& pathStack){
        string result = "";

        while(!pathStack.empty()){
            result += pathStack.front();
            pathStack.pop_front();
        }

        return result;
    }
    string simplifyPath(string path) {
        deque<string> pathStack; 
        
        int index = 0;
        while (index < path.size()){
            if (path[index] == '/'){
                for (index; path[index] == '/' && index < path.size() ;index++ );
                pathStack.push_back("/");
            } else {
                int start = index;
                for (index; path[index] != '/' && index < path.size(); index++);
                string folder(path.begin()+start, path.begin()+index);

                if (folder == "." || folder == ".."){
                    int times = folder.size();
                    if (times == 2) times++;
                    for (int i = 0; i < times && !pathStack.empty(); i++){
                        pathStack.pop_back();
                    }
                    continue;
                }
                pathStack.push_back(folder);

            }
        }
        if (pathStack.size() < 2 ) return "/";
        if (pathStack.front() != "/") pathStack.push_front("/");
        if (pathStack.back() == "/") pathStack.pop_back();
        return convertToString(pathStack);
    }
};