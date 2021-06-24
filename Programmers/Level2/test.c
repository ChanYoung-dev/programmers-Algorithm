bool checkSoSu(int n) {
    int i=n-1;
    while(i!=1) {
        if(n%i == 0) {
            return false;
        } else i--;
    }

    return true;
}