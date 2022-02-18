import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server{
	public static void main(String[] args) throws IOException{

		Socket socket = null;
		InputStreamReader inputStreamReader = null;
		OutputStreamWriter outputStreamWriter = null;
		BufferedReader bufferedReader = null;
		BufferedWriter bufferedWriter = null;
		ServerSocket serverSocket = null;

		//serverSocket = new ServerSocket(5000);

		if(args.length != 1){
			System.err.println("Uso desde consola: <numero puerto>");
			System.exit(1);
		}

		int numeroPuerto = Integer.parseInt(args[0]);

		try{
			while(true){
			
				serverSocket = new ServerSocket(numeroPuerto);
				socket = serverSocket.accept();

				inputStreamReader = new InputStreamReader(socket.getInputStream());
				outputStreamWriter = new OutputStreamWriter(socket.getOutputStream());

				bufferedReader = new BufferedReader(inputStreamReader);
				bufferedWriter = new BufferedWriter(outputStreamWriter);

				while(true){
					String msgFromClient = bufferedReader.readLine();
					System.out.println("Cliente: " + msgFromClient);

					if(msgFromClient.equalsIgnoreCase("Adios")){
						bufferedWriter.write("Adios");
						bufferedWriter.newLine();
						bufferedWriter.flush();
						break;
					}

					bufferedWriter.write("Hola que tal?");
					bufferedWriter.newLine();
					bufferedWriter.flush();
				}

				socket.close();
				inputStreamReader.close();
				outputStreamWriter.close();
				bufferedWriter.close();
				bufferedWriter.close();
			}
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}