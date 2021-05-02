class Solution {
public:
    map<int, Employee *> m;
    int getImportance(vector <Employee*> es, int id) {
        int n = es.size();
        for (int i = 0; i < n; i++) 
            m.insert({es[i]->id, es[i]});
        return getVal(id);
    }
    int getVal(int id) {
        Employee * master = m[id];
        int ans = master->importance;
        for (int & oid : master->subordinates) {
            Employee * other = m[oid];
            ans += other->importance;
            for (int & sub : other->subordinates) ans += getVal(sub);
        }
        return ans;
    }
};