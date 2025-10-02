import styles from 'css/style.css'
import styles from 'https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css'

export default function Header() {
  return (

    <nav class="navbar navbar-expand-lg navbar-light bg-light">
      <div class="container">
        <a class="navbar-brand" href="#">Joice Barros de Figueiredo</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav"
          aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
          <ul class="navbar-nav ml-auto">
            <li class="nav-item active">
              <a class="nav-link" href="JoiceBarros.html">Página Inicial</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="html/projetos.html">Projetos</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="html/clientes.html">Clientes</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="html/contatos.html">Contato</a>
            </li>
          </ul>
        </div>
      </div>
    </nav>
  )
}