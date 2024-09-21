class MyCalendar
{
    set<pair<int, int>> bookings;
    public:
        map<int, int> events;
    MyCalendar() {}
    bool book(int start, int end)
    {
        auto next = events.upper_bound(start);
        if (next != events.end() && (*next).second < end) return false;
        events.insert({ end,
            start });
        return true;
    }
};