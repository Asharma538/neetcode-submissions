class MedianFinder {
public:
    multiset<int> m1, m2;

    MedianFinder() {
        m1.clear(), m2.clear();
    }
    
    void addNum(int num) {
        if (m1.size()==0){
            m1.insert(num); return;
        }
        if (m1.size()==m2.size()){
            if (num>*m2.begin()){
                m1.insert(*m2.begin());
                m2.erase(m2.begin());
                m2.insert(num);
            } else {
                m1.insert(num);
            }
        } else {
            if (num>*m2.begin()){
                m2.insert(num);
            } else {
                m2.insert(*(--m1.end()));
                m1.erase(--m1.end());
                m1.insert(num);
            }
        }

        auto it = --m1.end();
        auto it2 = m2.begin();
        if (*it > *it2){
            int tmp = *it;
            int tmp2 = *it2;
            m1.erase(it);
            m2.erase(it2);
            
            m1.insert(tmp2);
            m2.insert(tmp);
        }
    }
    
    double findMedian() {
        if (m1.size()==m2.size()){
            return (double)(*(--m1.end())+*(m2.begin()))/2;
        } else {
            return (double)(*(--m1.end()));
        }
    }
};



