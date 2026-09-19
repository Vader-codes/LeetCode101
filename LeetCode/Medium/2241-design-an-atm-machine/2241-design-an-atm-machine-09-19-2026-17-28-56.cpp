class ATM {
public:
 vector<int>notes;
 int amt;
    ATM() {
        notes.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        amt = amount;
        int twenty = 0, fifty=0, hund =0, two_hund =0, five_hund =0;

        // take the max amonut of notes possible for 500 to 20
            five_hund = amt/500; // need this many 500 notes
            // check if we have thse many notes or not
            if(notes[4] >= five_hund){ // we have enough 
                amt = amt%500;    // take all remove the value
            }
            else{ // we do not have enough
                five_hund = notes[4]; // take all 
                amt-= (five_hund * 500);

            }

              two_hund = amt/200; // need this many 200 notes
            // check if we have thse many notes or not
            if(notes[3] >= two_hund){ // we have enough 
                amt = amt%200;    // take all remove the value
            }
            else{ // we do not have enough
                two_hund = notes[3]; // take all 
                amt-= (two_hund * 200);

            }

            
              hund = amt/100; // need this many 100 notes
            // check if we have thse many notes or not
            if(notes[2] >= hund){ // we have enough 
                amt = amt%100;    // take all remove the value
            }
            else{ // we do not have enough
                hund = notes[2]; // take all 
                amt-= (hund * 100);

            }

                 
              fifty = amt/50; // need this many 50 notes
            // check if we have thse many notes or not
            if(notes[1] >= fifty){ // we have enough 
                amt = amt%50;    // take all remove the value
            }
            else{ // we do not have enough
                fifty = notes[1]; // take all 
                amt-= (fifty * 50);

            }

                 
              twenty = amt/20; // need this many 20 notes
            // check if we have thse many notes or not
            if(notes[0] >= twenty){ // we have enough 
                amt = amt%20;    // take all remove the value
            }
            else{ // we do not have enough
                twenty = notes[0]; // take all 
                amt-= (twenty * 20);

            }
            if(amt == 0){
                notes[0] -= twenty;
                notes[1] -= fifty;
                notes[2] -= hund;
                notes[3] -= two_hund;
                notes[4] -= five_hund;
         return {twenty, fifty, hund, two_hund, five_hund};
            }
return {-1};
        


    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */