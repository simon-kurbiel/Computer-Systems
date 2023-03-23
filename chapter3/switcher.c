int switcher(int a, int b){
    int result = 0;
    switch (a)
    {
    case 0:
        result = result+1;
    case 1 :
        result = result+2;
    case 3 :
        result = result+3;
        break;
    case 4 :
    case  5:
        result = result+4;
        break;
    default:
        result = result-1;

        break;
    }
}