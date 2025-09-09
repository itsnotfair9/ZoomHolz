//SendRandomTreeNumber();           // die send funktion
          
void BaumscheibeAnimation() {          
          if ((counter >= 2) && (counter <= (ContractSpeed*1))) {
            digitalWrite(ring12, 1);
          }
          if ((counter >= (ContractSpeed*1)) && (counter <= (ContractSpeed*2))) {
            digitalWrite(ring12, 0);
            digitalWrite(ring11, 1);
          }
          if ((counter >= (ContractSpeed*2)) && (counter <= (ContractSpeed*3))) {
            digitalWrite(ring11, 0);
            digitalWrite(ring10, 1);
          }
          if ((counter >= (ContractSpeed*3)) && (counter <= (ContractSpeed*4))) {
            digitalWrite(ring10, 0);
            digitalWrite(ring09, 1);
          }
          if ((counter >= (ContractSpeed*4)) && (counter <= (ContractSpeed*5))) {
            digitalWrite(ring09, 0);
            digitalWrite(ring08, 1);
          }
          if ((counter >= (ContractSpeed*5)) && (counter <= (ContractSpeed*6))) {
            digitalWrite(ring08, 0);
            digitalWrite(ring07, 1);
          }
           if ((counter >= (ContractSpeed*6)) && (counter <= (ContractSpeed*7))) {
            digitalWrite(ring07, 0);
            digitalWrite(ring06, 1);
          }
             if ((counter >= (ContractSpeed*7)) && (counter <= (ContractSpeed*8))) {
            digitalWrite(ring06, 0);
            digitalWrite(ring05, 1);
          }
              if ((counter >= (ContractSpeed*8)) && (counter <= (ContractSpeed*9))) {
            digitalWrite(ring05, 0);
            digitalWrite(ring04, 1);
          }
               if ((counter >= (ContractSpeed*9)) && (counter <= (ContractSpeed*10))) {
            digitalWrite(ring04, 0);
            digitalWrite(ring03, 1);
          }
                 if ((counter >= (ContractSpeed*10)) && (counter <= (ContractSpeed*11))) {
            digitalWrite(ring03, 0);
            digitalWrite(ring02, 1);
          }
                 if ((counter >= (ContractSpeed*11)) && (counter <= (ContractSpeed*12))) {
            digitalWrite(ring02, 0);
            digitalWrite(ring01, 1);
          }
                 if ((counter >= (ContractSpeed*12)) && (counter <= (ContractSpeed*13))) {
            digitalWrite(ring01, 0);  
          }
/// fill up the tree with years
           if (counter >= (ContractSpeed*90)) {
            digitalWrite(ring01, 1);
          }
          if (counter >= (ContractSpeed*127)) {
            digitalWrite(ring02, 1);
          }
          if (counter >= (ContractSpeed*164)) {
            digitalWrite(ring03, 1);
          }
            if (counter >= (ContractSpeed*201)) {
            digitalWrite(ring04, 1);
          }
            if (counter >= (ContractSpeed*238)) {
            digitalWrite(ring05, 1);
          }
           if (counter >= (ContractSpeed*275)) {
            digitalWrite(ring06, 1);
          }
           if (counter >= (ContractSpeed*312)) {
            digitalWrite(ring07, 1);
          }
           if (counter >= (ContractSpeed*349)) {
            digitalWrite(ring08, 1);
          }
           if (counter >= (ContractSpeed*386)) {
            digitalWrite(ring09, 1);
          }
           if (counter >= (ContractSpeed*423)) {
            digitalWrite(ring10, 1);
          }
           if (counter >= (ContractSpeed*460)) {
            digitalWrite(ring11, 1);
          }
           if (counter >= (ContractSpeed*497)) {
            digitalWrite(ring12, 1);
          }

 // wait for end of video, then  switch of one by one
           if (counter >= (ContractSpeed*640)) {
            digitalWrite(ring01, 0);
          }
           if (counter >= (ContractSpeed*642)) {
            digitalWrite(ring02, 0);
          }
           if (counter >= (ContractSpeed*644)) {
            digitalWrite(ring03, 0);
          }
           if (counter >= (ContractSpeed*646)) {
            digitalWrite(ring04, 0);
          }
           if (counter >= (ContractSpeed*648)) {
            digitalWrite(ring05, 0);
          }
           if (counter >= (ContractSpeed*650)) {
            digitalWrite(ring06, 0);
          }
          if (counter >= (ContractSpeed*652)) {
            digitalWrite(ring07, 0);
          }
          if (counter >= (ContractSpeed*654)) {
            digitalWrite(ring08, 0);
          }
           if (counter >= (ContractSpeed*656)) {
            digitalWrite(ring09, 0);
          }
           if (counter >= (ContractSpeed*658)) {
            digitalWrite(ring10, 0);
          }
           if (counter >= (ContractSpeed*660)) {
            digitalWrite(ring11, 0);
          }
          if (counter >= (ContractSpeed*662)) {
            digitalWrite(ring12, 0);
            counter = 0;
            receivedChar = 'm';
          }
}
