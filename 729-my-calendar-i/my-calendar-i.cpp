class MyCalendar
{
    set<pair<int, int>> st;
    public:
        MyCalendar() {}

    bool book(int start, int end)
    {
        auto it = st.upper_bound({ start,
            end });
        if (it != st.end() && it->first < end) return false;

        if (it != st.begin() && prev(it)->second > start) return false;
        st.insert({start,end});
        return true;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */