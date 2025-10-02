package socket;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.net.Socket;
import java.rmi.RemoteException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import javax.swing.border.Border;

public class Cliente extends JFrame implements ActionListener, KeyListener {

    private String nome, mensagem;
    private int serverPort = 5555;
    private String address = "10.252.0.39";

    private JTextField txtMsg;
    private Font arial = new Font("Arial", Font.PLAIN, 12);
    private Border blankBorder = BorderFactory.createEmptyBorder(10, 10, 20, 10);// top,r,b,l
    private JPanel textPanel, inputPanel;

    private JList<String> list;
    private DefaultListModel<String> listModel;

    protected JTextArea textoArea, userArea;
    protected JButton btnSend, btnIniciar;
    protected JFrame frame;
    protected JPanel clientPanel, userPanel;

    private Socket socket;
    private OutputStream ou;
    private Writer ouw;
    private BufferedWriter bfw;

    //Construtor do Cliente
    public Cliente() {

        frame = new JFrame("Cliente");

        Container c = getContentPane();
        JPanel outerPanel = new JPanel(new BorderLayout());

        outerPanel.add(getInputPanel(), BorderLayout.CENTER);
        outerPanel.add(getTextPanel(), BorderLayout.NORTH);

        c.setLayout(new BorderLayout());
        c.add(outerPanel, BorderLayout.CENTER);
        c.add(getUsersPanel(), BorderLayout.WEST);

        frame.add(c);
        frame.pack();
        frame.setAlwaysOnTop(true);
        frame.setLocation(150, 150);
        txtMsg.requestFocus();

        frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
        frame.setVisible(true);

    }

    //Inicio do painel de historico das mensagens
    public JPanel getTextPanel() {
        String welcome = "Ola, bem vindo ao chat, Qual seu nome? \n";
        textoArea = new JTextArea(welcome, 14, 14);
        textoArea.setMargin(new Insets(10, 10, 10, 10));
        textoArea.setFont(arial);

        textoArea.setLineWrap(true);
        textoArea.setWrapStyleWord(true);
        textoArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textoArea);
        textPanel = new JPanel();
        textPanel.add(scrollPane);

        textPanel.setFont(new Font("Arial", Font.PLAIN, 12));

        return textPanel;
    }

    public JPanel getInputPanel() {
        inputPanel = new JPanel(new GridLayout(1, 1, 5, 5));
        inputPanel.setBorder(blankBorder);
        txtMsg = new JTextField();
        txtMsg.setFont(arial);
        inputPanel.add(txtMsg);
        return inputPanel;
    }

    public JPanel getUsersPanel() {

        userPanel = new JPanel(new BorderLayout());
        String userStr = "Usuarios";

        JLabel userLabel = new JLabel(userStr, JLabel.CENTER);
        userPanel.add(userLabel, BorderLayout.NORTH);
        userLabel.setFont(new Font("Arial", Font.PLAIN, 16));

        String[] noClientsYet = { " " };
        setClientPanel(noClientsYet);

        clientPanel.setFont(arial);
        userPanel.add(makeButtonPanel(), BorderLayout.SOUTH);
        userPanel.setBorder(blankBorder);

        return userPanel;
    }

    public void setClientPanel(String[] currClients) {
        clientPanel = new JPanel(new BorderLayout());
        listModel = new DefaultListModel<String>();

        for (String s : currClients) {
            listModel.addElement(s);
        }

        // Create the list and put it in a scroll pane.
        list = new JList<String>(listModel);
        list.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        list.setVisibleRowCount(8);
        list.setFont(arial);
        JScrollPane listScrollPane = new JScrollPane(list);

        clientPanel.add(listScrollPane, BorderLayout.CENTER);
        userPanel.add(clientPanel, BorderLayout.CENTER);
    }

    public JPanel makeButtonPanel() {
        btnSend = new JButton("Enviar ");
        btnSend.addActionListener(this);
        btnSend.setEnabled(false);

        btnIniciar = new JButton("Iniciar ");
        btnIniciar.addActionListener(this);

        JPanel buttonPanel = new JPanel(new GridLayout(4, 1));
        buttonPanel.add(new JLabel(""));
        buttonPanel.add(btnIniciar);
        buttonPanel.add(btnSend);

        return buttonPanel;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            // get connected to chat service
            if (e.getSource() == btnIniciar) {
                nome = txtMsg.getText();
                if (nome.length() != 0) {
                    frame.setTitle(nome);
                    txtMsg.setText("");
                    String conect ="USUARIO : " + nome + " conectou ao chat! \n";
                    textoArea.append(conect);
                    getConnected();

                    if (socket != null) {
                        btnIniciar.setEnabled(false);
                        btnSend.setEnabled(true);
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Coloque o nome e inicie \n");
                }
            }

            if (e.getSource() == btnSend) {
                mensagem = txtMsg.getText();
                txtMsg.setText("");
                enviar(mensagem);
                System.out.println("enviando mensagem : " + mensagem);
            }

        } catch (RemoteException remoteExc) {
            remoteExc.printStackTrace();
        } catch (IOException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void getConnected() throws IOException {

        socket = new Socket(this.address, this.serverPort);

        System.out.println("Host: " + address);

        ou = socket.getOutputStream();
        ouw = new OutputStreamWriter(ou);
        bfw = new BufferedWriter(ouw);
        bfw.write(nome + "\r\n");
        bfw.flush();

    }

    public void enviar(String msg) throws IOException {

        if (msg.equals("Sair")) {
            bfw.write("Desconectado \r\n");
            textoArea.append("Desconectado \r\n");
            sair();
            msg = "";
        } else {
            String mensagem = nome + " -> " + msg + "\r\n";
            bfw.write(mensagem);
            // textoArea.append(" diz -> " + msg + "\r\n");
        }
        bfw.flush();
        txtMsg.setText("");
    }

    public void escutar() throws IOException {

        InputStream in = socket.getInputStream();
        InputStreamReader inr = new InputStreamReader(in);
        BufferedReader bfr = new BufferedReader(inr);
        String msg = " ";
        while (true) {
            if (bfr.ready()) {
                msg = bfr.readLine();
                if (msg.equals("Sair")) {
                    sair();
                    textoArea.append("Servidor caiu! \r\n");
                } else {
                    textoArea.append(msg + "\r\n");
                }
            }
        }

    }

    public void sair() throws IOException {
        enviar("Sair");
        bfw.close();
        ouw.close();
        ou.close();
        socket.close();
    }

    @Override
    public void keyPressed(KeyEvent e) {

        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
            try {
                enviar(txtMsg.getText());

            } catch (IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }
    }

    @Override
    public void keyReleased(KeyEvent arg0) {
        // TODO Auto-generated method stub
    }

    @Override
    public void keyTyped(KeyEvent arg0) {
        // TODO Auto-generated method stub
    }

    public static void main(String[] args) throws IOException {

        Cliente c = new Cliente();

        c.addWindowListener(new WindowAdapter() {
            public void winClose(WindowEvent event) {
                System.exit(0);
            }
        });

        c.getConnected();
        c.escutar();

    }
}
