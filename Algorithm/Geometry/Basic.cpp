//Distance between 2 points
double distancePP(PT a, PT b){
    return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}

//Get the Orientation of a triangle
int orientation(PT p, PT q, PT r){
    double v=(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(v==0) return 0; //Colineares
    else if(v>0) return 1; //Horario
    else return 2; //AntiHorario
}

//
