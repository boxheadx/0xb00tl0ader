unsigned char strlen(const char far *str){
        unsigned char len = 0;
        while(*str++ != '\0'){
            len++;
        }
        return len;
}
