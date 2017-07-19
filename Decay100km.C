# include <iostream>
// Decay histograms for 100km

void Decay100km() {
    int uplim = 100000;
    // Makes stack for histograms
    THStack *result = new THStack("result","Decay Histogram(100km)");
    
    TF1 *hist100 = new TF1("hist100","exp(-0.01*x)",0.,uplim);
    TF1 *hist10 = new TF1("hist10","exp(-0.1*x)",0.,uplim);
    TF1 *hist1 = new TF1("hist1","exp(-1*x)",0.,uplim);
    TF1 *hist01 = new TF1("hist01","exp(-10*x)",0.,uplim);
    
    // Sets up individual histograms
    TH1F *vis = new TH1F("vis","Decay Histogram",100,0,uplim);
    vis->SetLineColor(kRed);
    TH1F *vis10 = new TH1F("vis10","Decay Histogram",100,0,uplim);
    vis10->SetLineColor(kGreen);
    TH1F *vis1 = new TH1F("vis1","Decay Histogram",100,0,uplim);
    vis1->SetLineColor(kBlue);
    TH1F *vis01 = new TH1F("vis01","Decay Histogram",100,0,uplim);
    vis01->SetLineColor(kBlack);
    
    // Random number generator
    TF1 *ranNum = new TF1("ranNum", "x", 0.,uplim);
    
    // Fills histograms
    for (int i=0;i<100000;i++) {
        double a = ranNum->GetRandom();
        vis->FillRandom("hist100");
        vis10->FillRandom("hist10");
        vis1->FillRandom("hist1");
        vis01->FillRandom("hist01");
    }
    
    // Adds to stack and draws
    result->Add(vis);
    result->Add(vis10);
    result->Add(vis1);
    result->Add(vis01);
    result->Draw("nostack");
    
}

int main(){
    Decay100km();
}
