using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using SkiProject.Managers;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthenticationController : ControllerBase
    {
        private readonly IAuthenticationManager authenticationManager;

        public AuthenticationController(IAuthenticationManager authenticationManager)
        {
            this.authenticationManager = authenticationManager;
        }

        [HttpPost("sign-up")]
        public async Task<IActionResult> SignUp([FromBody] RegisterModel registerModel)
        {
            await authenticationManager.Signup(registerModel);

            return Ok();
        }

        [HttpPost("login")]

        public async Task<IActionResult> Login([FromBody] LoginModel loginModel)
        {
            var tokens = await authenticationManager.Login(loginModel);

            if(tokens != null)
            {
                return Ok(tokens);
            }
            else
            {
                return BadRequest("Failed to login");
            }
        }
    }
}
