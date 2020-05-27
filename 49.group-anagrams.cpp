/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start


class Solution {
public:

    //third AC 2020.03.17 Time#91.63% Memory#100% using unordered_map
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> result;
        unordered_map<string,int> m;
        int i = 0;
        for(string &s:strs){
            string temp_s = s;
            sort(temp_s.begin(),temp_s.end());
            if(m.count(temp_s)==1)
                    result[m[temp_s]].push_back(s);
            else{
                result.push_back({});
                result.back().push_back(s);
                m[temp_s]= i;
                ++i;
            }
        }
        return result;
    }




    //second AC 2020.03.17 Time#5.08% Memory#100% too slow
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> result;
        vector<string> feature;
        for(string &s:strs){
            string temp_s = s;
            sort(temp_s.begin(),temp_s.end());

            bool tag = false;
            for(int i = 0;i<feature.size();++i){
                if(feature[i] == temp_s){
                    tag = true;
                    result[i].push_back(s);
                    break;
                }
            }
            if(!tag){
                result.push_back({});
                result.back().push_back(s);
                feature.push_back(temp_s);
            }
        }
        return result;
    }
    */



    //first AC 2020.03.16 Time#5.08% Memory#5.97% too slow
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<vector<pair<int,int> >> result_feature;
        vector<int> result_num;
        for(string &s:strs){
            int len = s.size();
            vector<int> v (26,0);
            vector<pair<int,int> > feature;
            for(int i = 0;i<len;++i)
                ++v[s[i]-'a'];
            for(int i = 0;i<26;++i){
                if(v[i]>0)
                    feature.push_back(make_pair(i,v[i]));
            }
            bool tag = false;
            for(int i = 0;i<result.size();++i){
                if(len == result_num[i]){
                    int j = 0;
                    for(j = 0;j<feature.size();++j){
                        if(feature[j].first== result_feature[i][j].first && feature[j].second == result_feature[i][j].second)
                            continue;
                        else break;
                    }
                    if(j == feature.size()){
                        result[i].push_back(s);
                        tag = true;
                        break;
                    }
                }
            }
            if(!tag){
                vector<string> new_v;
                new_v.push_back(s);
                result_feature.push_back(feature);
                result_num.push_back(len);
                result.push_back(new_v);
            }
        }
        return result; 
    }
    */
};
// @lc code=end

