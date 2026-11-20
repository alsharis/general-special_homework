struct node {
    array <node * , 26> alp;
    bool is_terminal = false;
    node () {      
    }
};
class Trie {
    node * root = nullptr;
    void add_str(string s) ;
    bool g[26][26];
    vector <int> topsort;
    bool used[26];
    void dfs(int v) ;
    void calc(string s) ;
};
