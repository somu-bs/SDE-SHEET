class Solution {
  
    struct meeting {
        int start;
        int end;
    };

    static bool comp(meeting a, meeting b) {
        return a.end < b.end;
    }
  
    public:
    int maxMeetings(int s[], int e[], int n)
    {
        struct meeting meet[n];
        for(int i = 0;i<n;i++) {
          meet[i].start = s[i];
          meet[i].end = e[i];
        }

        sort(meet, meet+n, comp);

        int limit = meet[0].end;
        int cnt = 1;

        for(int i = 1;i<n;i++) {
          if(meet[i].start > limit) {
            limit = meet[i].end;
            cnt++;
          }
        }
        return cnt;
    }
};
