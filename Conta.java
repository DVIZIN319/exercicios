package com.mycompany.contabancaria;

public class Conta{
    //atributos
    String titular;
    int numeroConta;
    double saldo;
    
    //construtor
    Conta(String nomeTitular, int numero, double saldoInicial){
        this.titular = nomeTitular;
        this.numeroConta = numero;
        this.saldo = saldoInicial;
    }
    
   //metodo
    
    void exibirDados(){
        System.out.println("Titular " + this.titular);
        System.out.println("Numero da conta  " + this.numeroConta);
        System.out.println("Saldo: " + this.saldo); 
    }
    
    void depositar(double valor){
        this.saldo = this.saldo + valor;
        System.out.println("Deposito de: R$" + valor);
        
    }
    double consultarSaldo(){
        return this.saldo;
    }
    boolean podeFazerEmprestimo(){
        if (this.saldo >= 1000){
            return true;
        } else{
            return false;
        }
    }
}
