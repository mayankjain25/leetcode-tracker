class SmallestInfiniteSet {
 set<int> S;
    int min;
public:
    SmallestInfiniteSet() {
        min=1;
    }
    
    int popSmallest() {
        if (!S.empty()){
            int x = *S.begin();
            S.erase(S.begin());
            return x;
        }
        return min++;
    }
    
    void addBack(int num) {
        if (num < min)
            S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */