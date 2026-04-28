/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.contabancaria;

/**
 *
 * @author Academico
 */
public class Contabancaria {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        // criando objeto
        Conta contaFisica = new Conta("Davi", 1234, 15);
        
        //chamando os metodos void
        contaFisica.exibirDados();
        contaFisica.depositar(400);
        
        //chamando metodos com retorno
        double saldoAtual = contaFisica.consultarSaldo();
        System.out.println("saldo atual " + saldoAtual);
        
        boolean podeEmprestimo = contaFisica.podeFazerEmprestimo();
        System.out.println("pode fazer emprestimo ? " + podeEmprestimo);
    }
    
}
