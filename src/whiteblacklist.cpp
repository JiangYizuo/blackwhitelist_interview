#include <iostream>
#include "whiteblacklist.h"
using namespace std;

#define WBLIST_GET_SEG_FROM_IT(__it, __seg) \
        do{ \
            (__seg).start = (__it)->first.start; \
            (__seg).end = (__it)->first.end == WBLIST_SAME_AS_START ? (__it)->first.start : (__it)->first.end;\
        }while(0)

#define WBLIST_PRE_DEL(__it) seg_map.erase(__it)

bool whiteblacklist::add_to_list(uint64_t start, uint64_t end, int toWhite){
#define WBLIST_ADD_NEW_SEG(__start, __end, __seg, __isWhite) \
    do{\
        (__seg).start = (__start); \
        (__seg).end = (__start) == (__end)?WBLIST_SAME_AS_START:(__end); \
        new_segs.push_back(make_pair(new_seg, __isWhite)); \
        new_segs_cnt++; \
    }while(0)
    cout<<endl<<"Add ("<<start<<","<<end<<"),"<<toWhite<<endl;
    segment_t seg_s = {start, start};
    seg_it_t it = seg_map.find(seg_s);
    vector< pair<segment_t, int> > new_segs;
    uint64_t new_segs_cnt = 0;
    segment_t new_seg;
    if(start == WBLIST_SAME_AS_START || end == WBLIST_SAME_AS_START)
        return false;
    while(it != seg_map.end()){
        //找到需要覆盖的区间
        segment_t seg;
        WBLIST_GET_SEG_FROM_IT(it, seg);
        if(seg.start < start)
        {
            if(seg.end < start){
                break;
            }
            if(toWhite != it->second){
                //拆分区间
                WBLIST_ADD_NEW_SEG(seg.start, start-1, new_seg, it->second);

                if(seg.end > end){
                    WBLIST_ADD_NEW_SEG(end+1, seg.end, new_seg, it->second);
                }
            }else{
                //合并区间
                if(seg.end >= end){
                    //区间已存在无需合并
                    print_all_segments();
                    return false;
                }
                WBLIST_ADD_NEW_SEG(seg.start, end, new_seg, it->second);
            }
            WBLIST_PRE_DEL(it);
        }else if(seg.start <= end){
            if(seg.end > end)
            {
                if(toWhite != it->second){
                    WBLIST_ADD_NEW_SEG(end+1, seg.end, new_seg, it->second);
                }else{
                    end = seg.end;
                }
            }
            WBLIST_PRE_DEL(it);
        }else{
            break;
        }
        it--;
    }
    WBLIST_ADD_NEW_SEG(start, end, new_seg, toWhite);
    add_segments(new_segs, new_segs_cnt);
    print_all_segments();
    return true;
}

void whiteblacklist::add_segments(const vector< pair<segment_t, int> > &new_segs, int count){
    for(int i=0; i<count; i++){
        seg_map.insert(new_segs[i]);
    }
}

bool whiteblacklist::is_in_whitelist(uint64_t number){
    segment_t seg = {number, number};
    seg_it_t it = seg_map.find(seg);
    if(it != seg_map.end())
    {
        cout<<number<<" is in "<< (it->second? "whitelist":"blacklist")
                <<"("<<it->first.start<<","
                <<(it->first.end == WBLIST_SAME_AS_START?it->first.start:it->first.end)
                <<")"<<endl;
        return it->second;
    }
    cout<<number<<" is not in any list."<<endl;
    return false;
}

void whiteblacklist::print_all_segments()
{
    seg_it_t it = seg_map.begin();
    cout<<"All segment:"<<endl;
    while(it != seg_map.end()){
        cout<<(it->second? "whitelist":"blacklist")
                        <<"("<<it->first.start<<","
                        <<(it->first.end == WBLIST_SAME_AS_START?it->first.start:it->first.end)
                        <<")"<<endl;
        it++;
    }
    cout<<endl;
}
