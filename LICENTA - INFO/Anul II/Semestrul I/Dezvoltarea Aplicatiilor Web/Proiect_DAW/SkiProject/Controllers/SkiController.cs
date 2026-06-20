using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SkiProject.Entities;
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
    public class SkiController : ControllerBase
    {
        private readonly ISkisManager manager;

        public SkiController(ISkisManager skisManager)
        {
            this.manager = skisManager;
        }

        [HttpGet]
        [Authorize(Policy = "Admin+User")]
        public async Task<IActionResult> GetSkis()
        {
            var skis = manager.GetSkis();

            return Ok(skis);
        }

        [HttpGet("with-brand")]
        [Authorize(Policy = "Admin+User")]
        public async Task<IActionResult> GetWithBrand()
        {
            var skis = manager.GetSkisWithBrand();

            return Ok(skis);
        }

        [HttpGet("ordered")]
        [Authorize(Policy = "Admin+User")]
        public async Task<IActionResult> GetOrdered()
        {
            var skis = manager.GetSkisWithBrandOrdered();

            return Ok(skis);
        }

        [HttpGet("byBrand/{id}")]
        [Authorize(Policy = "Admin+User")]
        public async Task<IActionResult> GetByBrand([FromRoute] string id)
        {
            var skis = manager.GetSkisByBrand(id);

            return Ok(skis);
        }
    
        [HttpGet("byId/{id}")]
        [Authorize(Policy = "BasicUser")]
        public async Task<IActionResult> GetById([FromRoute] string id)
        {
            var ski = manager.GetSkiById(id);

            return Ok(ski);
        }

        [HttpPost]
        [Authorize(Policy = "Admin")]
        public async Task<IActionResult> Create([FromBody] SkiModel skiModel)
        {
            manager.Create(skiModel);

            return Ok();
        }

        [HttpPut]
        [Authorize(Policy = "Admin")]
        public async Task<IActionResult> Update([FromBody] SkiModel skiModel)
        {
            manager.Update(skiModel);

            return Ok();
        }

        [HttpDelete("{id}")]
        [Authorize(Policy = "Admin")]
        public async Task<IActionResult> Delete([FromRoute] string id)
        {
            manager.Delete(id);

            return Ok();
        }

    }
}

