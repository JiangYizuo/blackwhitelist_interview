#ifndef WHITEBLACKLIST_H_
#define WHITEBLACKLIST_H_
#include<map>
#include<vector>
#include<inttypes.h>

class whiteblacklist{
public:
    typedef enum{
        BLACK,
        WHITE,
        BLANK
    }seg_type_t;
    typedef enum{
        SEG_ADDED,
        SEG_INVALIED,
        SEG_REMOVED,
        NOT_FOUND,
        IN_WHITE_LIST,
        IN_BLACK_LIST,
    }wblist_ret_t;

    whiteblacklist();
    void print_all_segments();
    wblist_ret_t query(uint64_t number);
    wblist_ret_t add(uint64_t start, uint64_t end, seg_type_t type);
    wblist_ret_t remove(uint64_t start);
private:
    static const uint64_t SAME_AS_START = 0;
    typedef struct segment{
        uint64_t start;
        uint64_t end;
        bool operator < (segment const & seg) const
        {
            //匹配区间时的比较
            if(seg.start == seg.end)
                return seg.start < start;
            if(start == end){
                if(seg.end != SAME_AS_START)
                    return start > seg.end;
                else
                    return start != seg.start;
            }
            //添加新区间的比较
            if(start > seg.start)
                return true;
            if(start == seg.start)
                return end > seg.end;
            return false;
        }
    }segment_t;
    typedef std::map <segment_t, seg_type_t>::iterator seg_it_t;
    std::map <segment_t, seg_type_t> seg_map;
    void add_segments(const std::vector< std::pair<segment_t, seg_type_t> > &new_segs, int count);
};
#endif /* WHITEBLACKLIST_H_ */
