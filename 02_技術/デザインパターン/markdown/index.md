デザインパターンについて
===

# 概要

この文章は下記のページの内容をまとめたものである。   
[矢沢久雄の早わかりGoFデザインパターン(1) | 日経 xTECH（クロステック）](http://tech.nikkeibp.co.jp/it/article/COLUMN/20051123/225074/)

## 目的

自分の頭の整理と、可能であれば後輩に知識を共有。

## 対象

コードが調べながら書けるようになってきた程度の人  
GoFデザインパターンに興味があるけど、自分で調べるのがめんどくさい人  

---

# デザインパターンとは？

- 様々なプログラムで再利用できる汎用的な設計パターンのこと

# GoFデザインパターンとは

## GoFとは

- The Gang Of Fourの略

	> GoFは、エーリヒ・ガンマ、リチャード・ヘルム、ラルフ・ジョンソン、ジョン・ブリシディースの4人である。  
	([wikipediaより引用)

## GoFデザインパターンとは

- Design Patterns : Elements of Reusable Object Oriented Software で紹介された23種類のデザインパターンのこと
  - 邦題は、オブジェクト指向における再利用のためのデザインパターン（ソフトバンクパブリッシング刊）
	- 通称GoF本

## 分類について

GoFデザインパターンは、全部で23種類あるが  
これらは下記の3つに分類される。

- 生成に関するパターン
- 構造に関するパターン
- 振る舞いに関するパターン

## 生成に関するパターン

### [Abstract Factory](./Abstract_Factory.html): 抽象的な工場
### [Builder](./Builder.html): 構築者
### [Factory Method](./Factory_Method.html): 工場メソッド
### [Prototype](./Prototype.html): 原型
### [Singleton](./Singleton.html): 一人っ子

## 構造に関するパターン

### [Adapter](./Adapter.html): 接続装置
### [Bridge](./Bridge.html): 橋
### [Composite](./Composite.html): 合成物
### [Decorator](./Decorator.html): 装飾者
### [Facade](./Facade.html): 見かけ
### [Flyweight](./Flyweight.html): 軽量級
### [Proxy](./Proxy.html): 代理人

## 振る舞いに関するパターン

### [Chain of Responsibility](./Chain_of_Responsibility.html)	責任の連鎖
### [Command](./Command.html)	命令
### [Interpreter](./Interpreter.html)	通訳
### [Iterator](./Iterator.html)	繰り返し
### [Mediator](./Mediator.html)	調停者
### [Memento](./Memento.html)	形見
### [Observer](./Observer.html)	観察者
### [State](./State.html)	状態
### [Strategy](./Strategy.html)	戦略
### [Template Method](./Template_Method.html)	ひな型メソッド
### [Visitor](./Visitor.html)	訪問者

