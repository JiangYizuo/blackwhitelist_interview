#ifndef WHITEBLACKLIST_H_
#define WHITEBLACKLIST_H_
#include<map>
#include<vector>
#include<inttypes.h>

#define WBLIST_SAME_AS_START 0
typedef class whiteblacklist{
    typedef struct segment{
        uint64_t start;
        uint64_t end;
        bool operator < (segment const & seg) const
        {
            //匹配区间时的比较
            if(seg.start == seg.end)
                return seg.start < start;
            if(start == end){
                if(seg.end != WBLIST_SAME_AS_START)
                    return start > seg.end;
                else
                    return start != seg.start;
            }
            //添加新区间的比较
            if(seg.start < start)
                return true;
            if(seg.start == start)
                return seg.end < end;
            return false;
        }
    }segment_t;
    typedef std::map <segment_t, int>::iterator seg_it_t;
    std::map <segment_t, int> seg_map;
    void add_segments(const std::vector< std::pair<segment_t, int> > &new_segs, int count);
public:
    void print_all_segments();
    bool is_in_whitelist(uint64_t number);
    bool add_to_list(uint64_t start, uint64_t end, int toWhite);
}whiteblacklist_t;

#endif /* WHITEBLACKLIST_H_ */
