Prototype
===

## 目的

- 同じクラスでいくつかのバリエーションを作成する。

## 背景(問題)

- 同じクラスでいくつかのバリエーションのオブジェクトをたくさん作りたい。

## 効果

- クラスの使用者が細かいパターンによって処理わけができる。

## 概要

- 実現する方法は簡単。自分のメンバ変数を利用してオブジェクトを返してあげるだけ。
  下記は例

		public Class Peolple(){
	
			private String name;
			private int age;
	
			public People(String name, int age){
				this.name=name;
				this.age=age;
			}
	
			public People clone(){
				return new People(this.name,this.int);
			}
		}

以上
