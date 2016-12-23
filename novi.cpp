void simulacija(int kolikoKoraka, bool ss = false) {

zivot kopija = zivot(this);

for (int k = 0; k < kolikoKoroka; k++) {
  zivot pom = zivot(width, height);
  for (int i = 0; i < width,)
     for (int j) {
          if (mapa[i][j] == DRVO) {
             ako je drvo prezivelo
             pom.dodajDrvo(i, j);
          }
      }
    if (ss == true) {
        cout << pom;
    }
    kopija = pom;
}

if (ss == false) {
    cout << kopija;
}

}

zivot z;

cout << unesti informacije za zivot << endl;
cin >> z;
