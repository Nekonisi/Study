package com.nekonisi.sample6;

import java.io.FileNotFoundException;

/**
 * @author nl_konishi
 * Step6内の実際の処理を記述するクラス
 */
public class Exec {
	
	/**
	 * Step6の処理を記述するメソッド
	 */
	public void exec() throws FileNotFoundException{
		
		try {
			System.out.println("Step6 商品レコード読込みプログラムを開始します。...¥r¥n");
			
			// 商品レコード呼び出し用のクラスをインスタンス化
			ProductRecord productRecord = new ProductRecord();
			productRecord.ReadFile();
			productRecord.SetProperty();
			
			int displayPrice=0;
			
			for (int i=0; i<productRecord.getRowCount(); i++) {
				// 商品名を表示
				System.out.print(productRecord.getProductName(i));
				
				// 表示用に単価 * 売上数量を計算
				displayPrice=Integer.parseInt(productRecord.getSales(i)) * Integer.parseInt(productRecord.getUnitPrice(i));
				System.out.println(" ¥¥" + displayPrice);
				
			}
			
		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			System.out.println("Step6の実行中にエラーが発生しました。");
			e.printStackTrace();
		} 
	}
}
