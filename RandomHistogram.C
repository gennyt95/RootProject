# include <iostream>

void RandomHistogram() {
    TF1 *randh = new TF1("randh","x",0.,100.);
    TH1F *vis = new TH1F("vis","Random Dist. Histogram",100,0,100);
    for (int i=0;i<100;i++) {
        vis->Fill(randh->GetRandom());
    }
    vis->Draw();
}

int main(){
    RandomHistogram();
}
