pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure') {
            steps {
                sh 'cmake -S . -B build -G Ninja'
            }
        }

        stage('Build') {
            steps {
                sh 'cmake --build build'
            }
        }

        stage('Run') {
            steps {
                sh './build/gestor_discos'
            }
        }
    }
}