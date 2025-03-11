/* Here we have to reverse a string wordwise. A method is that: 
  1. At first reverse the whole string. It will correct the position of each word. 
  2. Then individually we reverse each word for final result.
  For example, "The car"  . At first we reverse the whole string. "rac eht" . Then reverse each word individually. rac to car and eht to the.     */



  string reverseWords(string s) {
      string ans;
      reverse(s.begin(), s.end());
      for(int i=0; i<s.length(); i++){
          string w;
          while(i<s.size() && s[i] != ' '){
              w += s[i];
              i++;
          }
          reverse(w.begin(), w.end());
          if(w.size()>0){
              ans += " "+w;
          }
      }
      return ans.substr(1);
  }
