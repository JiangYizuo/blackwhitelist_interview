#include <iostream>
#include "whiteblacklist.h"
using namespace std;

#define WBLIST_GET_SEG_FROM_IT(__it, __seg) \
        do{ \
            (__seg).start = (__it)->first.start; \
            (__seg).end = (__it)->first.end; \
        }while(0)

#define WBLIST_PRE_DEL(__it) seg_map.erase(__it++)

whiteblacklist::whiteblacklist(){
    add(0, uint64_t(-1), BLANK);
}

whiteblacklist::wblist_ret_t whiteblacklist::add(uint64_t start, uint64_t end, seg_type_t type){
#define WBLIST_ADD_NEW_SEG(__start, __end, __type) \
    do{\
        segment_t new_seg; \
        new_seg.start = (__start); \
        new_seg.end = (__end); \
        new_segs.push_back(make_pair(new_seg, __type)); \
        new_segs_cnt++; \
    }while(0)
    if(start > end)
        return SEG_INVALIED;
    segment_t seg_s = {start, start};
    seg_it_t it = seg_map.find(seg_s);
    vector< pair<segment_t, seg_type_t> > new_segs;
    uint64_t new_segs_cnt = 0;
    segment_t seg_merged = {start, end};

    while(it != seg_map.end()){
        //找到需要覆盖的区间
        segment_t seg;
        seg_type_t old_type = it->second;
        WBLIST_GET_SEG_FROM_IT(it, seg);
        if(seg.start < start)
        {
            if(seg.end < start){
                break;
            }
            WBLIST_PRE_DEL(it);
            if(type != old_type){
                //拆分区间
                WBLIST_ADD_NEW_SEG(seg.start, start-1, old_type);
                if(seg.end > end){
                    WBLIST_ADD_NEW_SEG(end+1, seg.end, old_type);
                }
            }else{
                //合并区间
                seg_merged.start = seg.start;
                if(seg.end >= end){
                    seg_merged.end = seg.end;
                    break;
                }
            }
        }else if(seg.start <= end){
            if(seg.end > end)
            {
                if(type != old_type){
                    WBLIST_ADD_NEW_SEG(end+1, seg.end, old_type);
                }else{
                    seg_merged.end = seg.end;
                }
            }
            WBLIST_PRE_DEL(it);
        }else{
            break;
        }
    }
    WBLIST_ADD_NEW_SEG(seg_merged.start, seg_merged.end, type);
    add_segments(new_segs, new_segs_cnt);
    return SEG_ADDED;
}

whiteblacklist::wblist_ret_t whiteblacklist::remove(uint64_t start){
    segment_t seg_s = {start, start};
    seg_it_t it = seg_map.find(seg_s);
    if(it != seg_map.end()){
        if(it->first.start == start && it->second != BLANK){
            segment_t seg;
            WBLIST_GET_SEG_FROM_IT(it, seg);
            seg_map.erase(it);
            if(start>0){
                segment_t seg_pre_s = {start-1, start-1};
                it = seg_map.find(seg_pre_s);
                if(it!=seg_map.end()){
                    if(it->second == BLANK){
                        seg.start = it->first.start;
                        seg_map.erase(it);
                    }
                }
            }
            if(seg.end<(uint64_t)-1){
                segment_t seg_next_s = {seg.end+1, seg.end+1};
                it = seg_map.find(seg_next_s);
                if(it!=seg_map.end()){
                    if(it->second == BLANK){
                        seg.end = it->first.end;// == SAME_AS_START?it->first.start:it->first.end;
                        seg_map.erase(it);
                    }
                }
            }
            add(seg.start, seg.end, BLANK);
            return SEG_REMOVED;
        }
    }
    return NOT_FOUND;
}

void whiteblacklist::add_segments(const vector< pair<segment_t, seg_type_t> > &new_segs, int count){
    const vector< pair<segment_t, seg_type_t> >::iterator it;
    for(int i=0; i<count; i++){
        seg_map.insert(new_segs[i]);
    }
}

whiteblacklist::wblist_ret_t whiteblacklist::query(uint64_t number){
    segment_t seg = {number, number};
    seg_it_t it = seg_map.find(seg);
    if(it != seg_map.end()){

        return it->second == WHITE ? IN_WHITE_LIST:
                it->second == BLACK ? IN_BLACK_LIST:NOT_FOUND;
    }
    return NOT_FOUND;
}

whiteblacklist::wblist_ret_t whiteblacklist::query(uint64_t start, uint64_t end){
    if(start > end)
        return SEG_INVALIED;
    segment_t seg = {start, end};
    seg_it_t it = seg_map.find(seg);
    if(it != seg_map.end()){
        return it->second == WHITE ? IN_WHITE_LIST:
                it->second == BLACK ? IN_BLACK_LIST:NOT_FOUND;
    }
    return NOT_FOUND;
}

void whiteblacklist::print_all_segments()
{
    seg_it_t it = seg_map.begin();
    const string segname[] = {"BLACK", "WHITE", "BLANK"};
    if(it == seg_map.end()){
        cout<<"[empty]"<<endl;
        return;
    }
    while(it != seg_map.end()){
       // if(it->second != BLANK)
            cout<<segname[it->second]
                        <<"["<<it->first.start<<","
                        <<it->first.end
                        <<"]"<<endl;
        it++;
    }
}
