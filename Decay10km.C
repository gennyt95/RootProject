# include <iostream>

TH1F * makeLine(int uplim, int count) {
    TH1F *vis = new TH1F("vis","Decay Histogram",100,0,uplim);
    
    if(count == 1) {
        vis->SetLineColor(kRed);
    } else if(count == 2){
        vis->SetLineColor(kGreen);
    } else if(count == 3) {
        vis->SetLineColor(kBlue);
    } else {
        vis->SetLineColor(kBlack);
    }
    
    return vis;
}

void setup(int uplim, const char* name,TCanvas *c1,int spot) {
    // Makes TF1s
    
    TF1 *hist100 = new TF1("hist100","exp(-0.01*x)",0.,uplim);
    TF1 *hist10 = new TF1("hist10","exp(-0.1*x)",0.,uplim);
    TF1 *hist1 = new TF1("hist1","exp(-1*x)",0.,uplim);
    TF1 *hist01 = new TF1("hist01","exp(-10*x)",0.,uplim);
    
    // Makes lines
    
    TH1F *lineOne = makeLine(uplim, 1);
    lineOne->FillRandom("hist100", 100000);
    
    TH1F *lineTwo = makeLine(uplim, 2);
    lineTwo->FillRandom("hist10", 100000);
    
    TH1F *lineThree = makeLine(uplim, 3);
    lineThree->FillRandom("hist1", 100000);
    
    TH1F *lineFour = makeLine(uplim, 4);
    lineFour->FillRandom("hist01", 100000);
    
    // Makes stack and draws
    THStack *result = new THStack("result",name);
    
    result->Add(lineOne);
    result->Add(lineTwo);
    result->Add(lineThree);
    result->Add(lineFour);
    
    c1->cd(spot);
    result->Draw("nostack");
    
}


void Decay10km() {
    TCanvas *c1 = new TCanvas("c1","c1");
    c1->Divide(1,3);
    setup(100, "Decay Histogram 100m", c1, 1);
    setup(10000,"Decay Historgram 10km", c1, 2);
    setup(100000,"Decay Histogram 100km", c1, 3);
}

int main(){
    Decay10km();
}

