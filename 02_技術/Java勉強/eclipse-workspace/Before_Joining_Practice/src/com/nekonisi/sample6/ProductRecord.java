package com.nekonisi.sample6;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author nl_konishi
 * 商品レコードクラス
 */
/**
 * @author nl_konishi
 *
 */
public class ProductRecord {

	// {{ 定数
	/**
	 * テキストファイル、デフォルトの読込みパス
	 */
	private static final String DEFAULT_PATH="D:\\syohin.txt";

	/**
	 *  商品コードのバイト数
	 */
	private static final int PRODUCT_CODE_BYTE=5;

	/**
	 * 商品名のバイト数
	 */
	//private static final int PRODUCT_NAME_BYTE=40;
	private static final int PRODUCT_NAME_BYTE=20;

	/**
	 * 単価
	 */
	private static final int UNIT_PRICE_BYTE=6;

	/**
	 * 売上数量
	 */
	private static final int SALES_BYTE=3;

	/**
	 * 在庫数
	 */
	private static final int STOCK_BYTE=3;

	/**
	 * 備考
	 */
	private static final int REMARKS_BYTE=21;

	// }}

	// {{ プロパティ

	/**
	 * テキストファイルのパス
	 */
	private String recordFilePath="";

	/**
	 * テキストファイルオブジェクト
	 */
	private File txtFile = null;

	/**
	 * ファイル内の文字列 添え字は行数
	 */
	private List<String> readString = new ArrayList<String>();

	/**
	 * 商品コードのリスト
	 */
	private List<String> productCode = new ArrayList<String>();

	/**
	 * 商品名のリスト
	 */
	private List<String> productName = new ArrayList<String>();

	/**
	 * 単価リスト
	 */
	private List<String> unitPrice = new ArrayList<String>();

	/**
	 * 売上数量のリスト
	 */
	private List<String> sales = new ArrayList<String>();

	/**
	 * 在庫のリスト
	 */
	private List<String> stock = new ArrayList<String>();

	/**
	 * 備考のリスト
	 */
	private List<String> remark = new ArrayList<String>();

	// }}

	// {{ コンストラクタ

	// 
	/**
	 * テキストファイルのパスを指定しないコンストラクタ
	 * デフォルト値として、D:¥syohin.txtを指定
	 */
	public ProductRecord() throws FileNotFoundException{
		try {
			//プロパティに引数で指定されたパスを格納
			this.recordFilePath= DEFAULT_PATH;
			this.txtFile = new File(this.recordFilePath);

			// ファイルの存在チェック
			if (!txtFile.exists()){
				// ファイルが存在しない場合
				throw new FileNotFoundException("指定されたパスにテキストファイルが見つかりません。");
			}

			System.out.println("[" + this.recordFilePath +"]を読み込みました。");

		} catch (Exception e) {
			// TODO: handle exception
			throw e;
		}
	}

	// {{ getter, setter
	/**
	 * @return 商品レコードのテキストファイルのパス
	 */
	public String getRecordFilePath() {
		return recordFilePath;
	}

	/**
	 * @param recordFilePath 商品レコードのテキストファイルのパス
	 */
	public void setRecordFilePath(String recordFilePath) {
		this.recordFilePath = recordFilePath;
	}

	/**
	 * @return テキストファイルオブジェクト
	 */
	public File getTxtFile() {
		return txtFile;
	}

	/**
	 * @param txtFile テキストファイルオブジェクト
	 */
	public void setTxtFile(File txtFile) {
		this.txtFile = txtFile;
	}

	/**
	 * @param rowNumner 行数
	 * @return 指定された行数の文字列
	 */
	public String getReadString(int rowNumner) {
		return readString.get(rowNumner);
	}

	/**
	 * @return テキストファイルの行数
	 */
	public int getRowCount() {
		return this.readString.size();
	}

	/**
	 * @param readString セットしたい文字列のリスト
	 */
	public void setReadString(List<String> readString) {
		this.readString = readString;
	}
	
	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の商品コード
	 */
	public String getProductCode(int rowNumber) {
		return productCode.get(rowNumber) ;
	}

	/**
	 * @param productCode 追加したい商品コード
	 * 引数として渡された文字列を商品コードリストに追加します。
	 */
	public void setProductCode(String productCode) {
		this.productCode.add(productCode);
	}

	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の商品名
	 */
	public String getProductName(int rowNumber) {
		return productName.get(rowNumber);
	}

	/**
	 * @param productName 追加したい商品名
	 * 引数として渡された文字列を商品名リストに追加します。
	 */
	public void setProductName(String productName) {
		this.productName.add(productName);
	}

	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の単価
	 */
	public String getUnitPrice(int rowNumber) {
		return unitPrice.get(rowNumber);
	}

	/**
	 * @param unitPrice 追加したい単価
	 * 引数として渡された文字列を単価リストに追加します。
	 */
	public void setUnitPrice(String unitPrice) {
		this.unitPrice.add(unitPrice);
	}

	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の売上数量
	 */
	public String getSales(int rowNumber) {
		return sales.get(rowNumber);
	}

	/**
	 * @param sales 追加したい売上数量
	 * 引数として渡された文字列を売上数量リストに追加します。
	 */
	public void setSales(String sales) {
		this.sales.add(sales);
	}

	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の在庫数
	 */
	public String getStock(int rowNumber) {
		return stock.get(rowNumber);
	}

	/**
	 * @param stock 追加したい在庫数
	 * 引数として渡された文字列を在庫数リストに追加します。
	 */
	public void setStock(String stock) {
		this.stock.add(stock);
	}

	/**
	 * @param rowNumber 行番号
	 * @return 指定した行番号の備考
	 */
	public String getRemark(int rowNumber) {
		return this.remark.get(rowNumber);
	}

	/**
	 * @param remark 追加したい備考の内容
	 * 引数として渡された文字列を備考リストに追加します。
	 */
	public void setRemark(String remark) {
		this.remark.add(remark);
	}

	public List<String> getReadString() {
		return readString;
	}

	//	}}
	/**
	 * @param recordFilePath 商品レコードのフルパス
	 * テキストファイルのパスを指定したコンストラクタ
	 */
	public ProductRecord(String recordFilePath) throws FileNotFoundException{

		try {
			//プロパティに引数で指定されたパスを格納
			this.recordFilePath=recordFilePath;
			this.txtFile = new File(this.recordFilePath);

			// ファイルの存在チェック
			if (!txtFile.exists()){
				// ファイルが存在しない場合
				throw new FileNotFoundException("指定されたパスにテキストファイルが見つかりません。");
			}

			System.out.println("[" + this.recordFilePath +"]を読み込みました。");
		} catch (FileNotFoundException e) {
			throw e;
		}

	}
	// }}

	// {{ メソッド

	/**
	 * 指定ファイルの読込を行う
	 */
	public void ReadFile() {
		try (BufferedReader bufferReader = new BufferedReader(new FileReader(this.txtFile));)
		{
			String readString="";
			while((readString = bufferReader.readLine()) != null){
				this.readString.add(readString);
			}
			bufferReader.close();

		} catch (FileNotFoundException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} 		
	}
	
	public ProductRecord SetProperty() throws Exception {
		
		try {
			
			// 文字列切り取りの開始位置
			int startPosition=0;
			
			// 文字列切り取りの終了位置
			int endPosition=0;
			
			// プロパティに格納する文字列
			String[] inputData=new String[6];
			/*========================================
			 readStringの中身をforeach文で取得
			 strData -> 一行分のデータ 
			 ========================================*/			
			for(String strData : readString) {
				
				// 行データから、商品コードのデータを切り出し
				startPosition=0;
				endPosition=PRODUCT_CODE_BYTE;
				inputData[0]=strData.substring(startPosition,endPosition);
				
				// 行データから、商品名のデータを切り出し
				startPosition=endPosition;
				endPosition=endPosition+PRODUCT_NAME_BYTE;
				inputData[1]=strData.substring(startPosition,endPosition);
				
				// 行データから、単価データの切り出し
				startPosition=endPosition;
				endPosition=endPosition+UNIT_PRICE_BYTE;
				inputData[2]=strData.substring(startPosition,endPosition);
				
				// 行データから、売上数量データの切り出し
				startPosition=endPosition;
				endPosition=endPosition+SALES_BYTE;
				inputData[3]=strData.substring(startPosition,endPosition);
				
				// 行データから、在庫数データの切り出し
				startPosition=endPosition;
				endPosition=endPosition+STOCK_BYTE;
				inputData[4]=strData.substring(startPosition,endPosition);

				// 行データから、備考データの切り出し
				startPosition=endPosition;
				endPosition=endPosition+REMARKS_BYTE;
				inputData[5]=strData.substring(startPosition,endPosition);

				// それぞれプロパティに格納 inputData配列の初期化[
				this.setProductCode(inputData[0]);
				this.setProductName(inputData[1]);
				this.setUnitPrice(inputData[2]);
				this.setSales(inputData[3]);
				this.setStock(inputData[4]);
				this.setRemark(inputData[5]);
				
			}
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			throw new Exception("プロパティのセットに失敗しました。");
		}
		return this;
		
	}

	// }}
}

