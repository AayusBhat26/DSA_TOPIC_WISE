#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        /*
        0. sorting the meetings array so that we can have meetings with earliest start time first
        1. end time is not the part of our meeting
        2. meeting will take place in unused rooms with the lowest number
        3. if there are no free rooms, then the meeting would be delayed until a room becomes free, the duration of the meeting would be same but end time would increase as we have to wait for the room to be available.
        4. when a room becomes empty or available, the room with earliest start time would be allocated first.
        5. we need to return the room number which holds maximum number of meetings
        6. we need to keep a track of minimum index priority so that each meeting is possibly held in the lowest index room possible.
        7. we will use an array to keep track of count of meetings held in a specific room
        */

        /*
            Since, in the 2nd point, we want the smallest room for the first meeting, so we will use priority queue (min heap) to store the minimum room number which is available, initially all the rooms would be available.

        */

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++)
        {
            unusedRooms.push(i);
        }

        // maximum count for resultant
        vector<int> count(n, 0); // initially, every room would held 0 meetings
        int roomNumber = 0;      // room number that is going to held the maximum number meeting

        /*
            in order to keep track of the rooms that are being used, we need to declare a priority queue so that we can have room with minimum amount of time and the room number direct access to minimum end time
        */
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;

        // traversing through the meetings vector
        for (int i = 0; i < meetings.size(); i++)
        {

            long long startTime = meetings[i][0];
            long long endTime = meetings[i][1];
            long long duration = endTime - startTime;
            /*
                we need to get all the rooms whose end time is less than or equal to the starting of the next meeting, so that we can have minimum index priority for the meeting

            */
            // for current meeting, get all the rooms that are being used and pop all those rooms whose meeting is going to end before or at the start time of current meeting. So all these rooms would become used for a unit of time
            while (!usedRooms.empty() && usedRooms.top().first <= startTime)
            {
                int roomNumber = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(roomNumber);
            }
            /*
                if we have rooms available with us, we would push the end time of the room and the room number to the used room queue

                for the current meeting, we need only one room to be empty that is why we are not using while loop, we are just getting the top element from the min heap so that we can assign that room with the meeting's end time and room number.
            */
            if (!unusedRooms.empty())
            {
                int roomNumber = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({endTime, roomNumber});
                count[roomNumber]++;
            }
            // we have no more rooms avaiable, get the first avaialble room from usedRooms heap and update the room number's end time and push back the updated end time and room number
            else
            {
                pair<long long, int> currentNode = usedRooms.top();
                usedRooms.pop();
                long long meetEndTime = currentNode.first;
                int roomNumber = currentNode.second;
                usedRooms.push({meetEndTime + duration, roomNumber});
                count[roomNumber]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (count[i] > count[roomNumber])
            {
                roomNumber = i;
            }
        }

        return roomNumber;
    }
};