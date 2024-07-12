class MedianFinder
{
    int counter = 0;
    vector<int> vec;
    public:
        MedianFinder() {}

    void addNum(int num)
    {
        vec.insert(lower_bound(vec.begin(), vec.end(), num), num);
        counter++;
    }

    double findMedian()
    {
        if (counter % 2 != 0) return vec[counter / 2];
        return (double)(vec[counter / 2] + vec[counter / 2 - 1]) / 2;
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */