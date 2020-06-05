vector Solution::insert(vector &intervals, Interval newInterval) {
vector ans;

if(newInterval.end < newInterval.start){
int t = newInterval.end;
newInterval.end = newInterval.start;
newInterval.start = t;
}
Interval temp;
temp.start=-1;
temp.end=-1;
int done=0;
for(int i=0;i<intervals.size();i++){
if(!done){
if(intervals[i].start <= newInterval.start){
//case 4
if(intervals[i].end <= newInterval.start){
ans.push_back(intervals[i]);
}
else{
//cout << “here1”<<endl;
temp.start = intervals[i].start;
}
}

     else if(intervals[i].start > newInterval.start){
         if(temp.start==-1)
             temp.start = newInterval.start;
         if(newInterval.end < intervals[i].start){
             temp.end = newInterval.end;
             ans.push_back(temp);
             done=1;
             ans.push_back(intervals[i]);
         }
         else if(newInterval.end <= intervals[i].end){
             temp.end = intervals[i].end;
             ans.push_back(temp);
             done=1;
         }
     }
 }
 else{
     ans.push_back(intervals[i]);
 }
}
if(!done){
if(temp.start!=-1){
temp.end=newInterval.end;
ans.push_back(temp);
}
else
ans.push_back(newInterval);
}
return ans;
}