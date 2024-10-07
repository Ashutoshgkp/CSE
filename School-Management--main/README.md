# School Management System

This is a Django-based School Management System that allows administrators to manage various aspects of a school, including student records, staff details, courses, and more.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Admin Access](#admin-access)
- [Requirements](#requirements)
- [Contributing](#contributing)
- [License](#license)

## Features

- Manage student records, including admission, attendance, and grades.
- Manage staff information and roles.
- Handle course creation and enrollment.
- User-friendly interface with customizable widgets.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/school-management-system.git
   cd school-management-system
   ```

2. Install the required packages:
   ```bash
   pip install -r requirements.txt
   ```

3. Make database migrations:
   ```bash
   python manage.py makemigrations
   python manage.py migrate
   ```

4. Run the application:
   ```bash
   python manage.py runserver
   ```

## Usage

- After running the server, navigate to `http://127.0.0.1:8000/` in your web browser.
- Create an account or log in as an admin to start managing school data.

## Admin Access

To access the admin panel, you need to create a superuser account:

```bash
python manage.py createsuperuser
```

Follow the prompts to create the admin account. Afterward, you can log in at `http://127.0.0.1:8000/admin/` to manage the application.

## Requirements

The project is built using the following dependencies:

- Django==3.0.5
- asgiref==3.2.7
- django-widget-tweaks==1.4.8
- pytz==2020.1
- sqlparse==0.3.1

These can be installed using the command mentioned in the installation section.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any bug fixes or feature enhancements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
