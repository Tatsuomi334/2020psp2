# 課題4 レポート

bb35319029 中岡辰浩

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
性別、身長と学籍番号のデータを読み込み、もし学籍番号があれば、性別と身長を表示し、なかったら  NO DATAを出力する。


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : c
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200720 sonoda]
- まず，関数中に出てくる14とか15は，マクロ定義で書きましょう
  ```
  #define N 14
  ```
  として，15はN+1，14はNですね．
- ID.csvは1行目からデータが始まりますが，heights.csvの1行目は項目名なのでこちらは1行読み飛ばさないと，データの数が合わないです．
- 基本的な考え方は，入力された調べるID `iID`? と一致する`DATA[i].ID`をfor文で回しながら探し，探し当てたそのデータの`i`について，`DATA[i].height`などを出力する．探し当てられなかったら，`no data`を出力，という流れだと思います．

[comment0721宮下]

課題提出お疲れさまでした！修正点があります。

- L41 空読みは文字通り無駄に1行読む処理です。なのでメールでのヒントの通りwhile文の上の行（外）でないといけません。
- L18,42 genderは整数なのでintで定義しましょう。なのでL42も％dです
- L61 scanf -> sscanf です。違いは手入力かファイルからの入力かです。
- L48 printf("Input the filename of sample ID: %s\n",fname2); 
  -> printf("Input the filename of sample ID:");で大丈夫です。改行は不要で、ファイル名を入力する前に出力しようとしています。
  
ここまですればこちらの環境では正しく動きました。もう少しだと思います、頑張ってください！