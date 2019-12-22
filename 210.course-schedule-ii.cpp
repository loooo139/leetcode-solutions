/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (37.25%)
 * Likes:    1402
 * Dislikes: 96
 * Total Accepted:    194.9K
 * Total Submissions: 522.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edge(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0],b=prerequisites[i][1];
            edge[b].push_back(a);
            indegree[a]++;
        }
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        vector<int>res;
        while(!que.empty()){
            auto t=que.front();
            que.pop();
            res.push_back(t);
            for(int i=0;i<edge[t].size();i++){
                int tmp=edge[t][i];
                indegree[tmp]--;
                if(indegree[tmp]==0){
                    que.push(tmp);
                }
            }
        }
        if(res.size()!=numCourses){
            res.clear();
        };
        return res;
        
    }
};
// @lc code=end

