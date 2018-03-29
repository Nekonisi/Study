# Gradient

## 概要

- グラデーションを定義する

## プロパティ

### stops: list<GradientStop>

- グラデーションの境界を指定する

## サンプル

	Rectangle {
	    width: 100; height: 100
	    gradient: Gradient {
	        GradientStop { position: 0.0; color: "red" }
	        GradientStop { position: 0.33; color: "yellow" }
	        GradientStop { position: 1.0; color: "green" }
	    }
	}

以上
