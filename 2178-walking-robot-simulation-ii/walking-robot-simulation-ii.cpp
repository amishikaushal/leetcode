class Robot {
private:    
    int x , y ;
    int d ;

    int w , h;
    int tot;

public:
    Robot(int width, int height) {
        x = 0;
        y = 0;

        d = 1;

        w = width;
        h = height;

        tot = 2 * w;
        tot += 2 * (h - 2);
    }
    
    void step(int num) {

        if(num % tot == 0 && x == 0 && y == 0){
            d = 2;
        }
        num %= tot;

        while(num){
            if(d == 1){
                int step = w - x - 1;
                step = min(step , num);

                x += step;
                num -= step;
            }

            else if(d == 0){
                int step = h - y - 1;
                step = min(step , num);

                y += step;
                num -= step;
            }

            else if(d == 3){
                int step = min(x , num);

                x -= step;
                num -= step;
            }

            else if(d == 2){
                int step = min(y , num);

                y -= step;
                num -= step;
            }


            if(num){
                d = (d - 1 + 4) % 4;
            }
        }
    }
    
    vector<int> getPos() {
        return {x , y};
    }
    
    string getDir() {
        if(d == 1) return "East";
        if(d == 0) return "North";
        if(d == 3) return "West";

        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */