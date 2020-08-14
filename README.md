# AOJ
Aizu Online Judge の Introduction to Algorithms and Data Structures 
を解くことでアルゴリズムとデータ構造の扱い方や考え方を知る

**プログラミングコンテストの攻略のためのアルゴリズムとデータ構造**
別名 「螺旋本」 と呼ばれる本を読みながら解いている

以下のことを注意して解いた
- グローバル関数を使わない (constexprがついたものは除く)
- 出来るところは値渡しではなく参照渡しを使用する
- 競プロで使用されがちな #include <bits/stdc++.h> は使用しない
- repマクロ ( #defing rep(i, n) for(int i = 0; i < (n); ++i) ) などは使用しない
- わかりにくそうなところはコメントをつける
- 極力マジックナンバーを減らす
- 値が書き換わらない組込型以外の型にはconstをつける

しかし、以下の点は大目に見て許してください
- using namespace std; を使用している
- Gitのコミットメッセージが雑
- branch は master しか使っていない
