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
                sh 'cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release'
            }
        }

        stage('Build') {
            steps {
                sh 'cmake --build build'
            }
        }

        stage('Run app') {
            steps {
                sh './build/gestor_discos'
            }
        }

        stage('Run tests') {
            steps {
                sh 'ctest --test-dir build --output-on-failure'
            }
        }
    }
}