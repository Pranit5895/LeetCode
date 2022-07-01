class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Idea: Sort & Greedy
        std::sort(boxTypes.begin(), boxTypes.end(), 
            [](vector<int>& a, vector<int>& b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
        });
        int res_units = 0, cur_truck_size = 0;
        for(auto& box : boxTypes){
            for(int box_cnt=box[0]; box_cnt>=0; box_cnt--){
                if( (cur_truck_size + box_cnt) <= truckSize ){
                    cur_truck_size += box_cnt;
                    res_units += (box_cnt * box[1]);
                    break;
                }
            } if( cur_truck_size == truckSize ) break;
        } return res_units;
    }
};
