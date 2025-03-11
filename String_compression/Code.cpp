void compress(string &chars) {
    int ind = 0;
    for(int i=0; i<chars.size(); i++){
        char c = chars[i];
        int count = 0;
        while(i<chars.size() && chars[i]==c){
            count++;
            i++;
        }
        if(count == 1){
            chars[ind] = c;
            ind ++;
        }else{
            chars[ind] = c;
            ind++;
            string s = to_string(count);
            for(char ch : s){
                chars[ind] = ch;
                ind++;
            }
        }
        i--;
    }
    chars.resize(ind);
}
