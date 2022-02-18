import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client{
	public static void main(String[] args){
		Socket socket = null;
		InputStreamReader inputStreamReader = null;
		OutputStreamWriter outputStreamWriter = null;
		BufferedReader bufferedReader = null;
		BufferedWriter bufferedWriter = null;

		try{
			socket = new Socket("localhost", 5000);
			inputStreamReader = new InputStreamReader(socket.getInputStream());
			outputStreamWriter = new OutputStreamWriter(socket.getOutputStream());

			bufferedReader = new BufferedReader(inputStreamReader);
			bufferedWriter = new BufferedWriter(outputStreamWriter);

			Scanner scanner = new Scanner(System.in);

			int num, ans;

			while(true){
				String buffer = bufferedReader.readLine();
				System.out.println("Servidor - " + buffer);

				num = Integer.parseInt(scanner.nextLine());
				bufferedWriter.write(num);
				bufferedWriter.flush();

				if(num == 0){
					System.out.println("Salida con exito");
					break;
				}

				ans = bufferedReader.read();
				System.out.println("Servidor - La respuesta es: " + ans);
			}
		} catch(IOException e){
			e.printStackTrace();
		} finally{
			try{
				if(socket != null)
					socket.close();
				if(inputStreamReader != null)
					inputStreamReader.close();
				if(outputStreamWriter != null)
					outputStreamWriter.close();
				if(bufferedWriter != null)
					bufferedWriter.close();
				if(bufferedReader != null)
					bufferedReader.close();
			} catch(IOException e){
				e.printStackTrace();
			}
		}

	}
}